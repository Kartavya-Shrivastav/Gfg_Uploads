<?php
session_start();

// Connect to MySQL server
$conn = new mysqli("localhost", "root", "");
$conn->query("CREATE DATABASE IF NOT EXISTS gardening");
$conn->select_db("gardening");

// Create users table if not exists
$conn->query("CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50), email VARCHAR(100),
    password VARCHAR(255), style VARCHAR(50),
    attempts INT DEFAULT 0, locked_until INT DEFAULT 0
)");

function sendWelcome($email)
{
    function sendWelcome($email) {
    $subject = "Welcome to Gardening Community!";
    $message = "Hi there!\n\nThank you for registering on our Gardening Portal.\nWe're glad to have you!";
    $headers = "From: no-reply@gardening.com";

    if (mail($email, $subject, $message, $headers)) {
        echo "<p>Welcome email sent to $email</p>";
    } else {
        echo "<p>Failed to send email to $email</p>";
    }
}

}

// Registration
if (isset($_POST['register'])) {
    $u = $_POST['username'];
    $e = $_POST['email'];
    $p = password_hash($_POST['password'], PASSWORD_DEFAULT);
    $s = $_POST['style'];
    $conn->query("INSERT INTO users (username, email, password, style) VALUES ('$u', '$e', '$p', '$s')");
    setcookie("remember", $u, time() + 3600);
    sendWelcome($e);
    echo "Registered!";
}

// Login
if (isset($_POST['login'])) {
    $u = $_POST['username'];
    $p = $_POST['password'];
    $res = $conn->query("SELECT * FROM users WHERE username='$u'");
    if ($row = $res->fetch_assoc()) {
        if (time() < $row['locked_until']) {
            echo "Maximum Attempts reached.<br>Locked. Try at " . date("H:i:s", $row['locked_until']);
        } elseif (password_verify($p, $row['password'])) {
            $_SESSION['user'] = $u;
            $conn->query("UPDATE users SET attempts=0, locked_until=0 WHERE username='$u'");
            echo "Welcome $u!";
        } else {
            $a = $row['attempts'] + 1;
            $lock = $a >= 3 ? time() + 300 : 0;
            $conn->query("UPDATE users SET attempts=$a, locked_until=$lock WHERE username='$u'");
            echo "Failed login. Attempts: $a";
        }
    } else
        echo "User not found!";
}

// Logout
if (isset($_GET['logout'])) {
    session_destroy();
    echo "<br>Logged out!";
}
?>

<!-- HTML Form -->
<h2>Register</h2>
<form method="post">
    Username <input name="username" required><br>
    Email <input name="email" type="email" required><br>
    Password <input name="password" type="password" required><br>
    Style <select name="style">
        <option>Organic</option>
        <option>Hydroponic</option>
        <option>Urban</option>
    </select><br>
    <button name="register">Register</button>
</form>

<h2>Login</h2>
<form method="post">
    Username <input name="username" value="<?= $_COOKIE['remember'] ?? '' ?>" required><br>
    Password <input name="password" type="password" required><br>
    <button name="login">Login</button>
</form>

<?php if (isset($_SESSION['user'])): ?>
    <p>You are logged in as <?= $_SESSION['user'] ?> <a href="?logout=1">Logout</a></p>
<?php endif ?>