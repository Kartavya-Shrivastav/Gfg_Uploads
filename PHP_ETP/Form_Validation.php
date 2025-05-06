<?php
$name = $email = "";
$errors = [];
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = htmlspecialchars(trim($_POST["name"] ?? ""));
    $email = filter_var(trim($_POST["email"] ?? "") , FILTER_VALIDATE_EMAIL);
    $pass = $_POST["pass"] ?? "";

    if (!$name)
        $errors[] = "Name is required.";
    if (!filter_var($email, FILTER_VALIDATE_EMAIL))
        $errors[] = "Invalid email format.";
    if (strlen($pass) < 8)
        $errors[] = "Password must be at least 8 characters.";
    if (!preg_match("/[A-Z]/", $pass))
        $errors[] = "Password must contain an uppercase letter.";
    if (!preg_match("/\d/", $pass))
        $errors[] = "Password must contain a digit.";
    if (!preg_match("/[^a-zA-Z\d]/", $pass))
        $errors[] = "Password must contain a special character.";

    if (!$errors) {
        echo "<h2>Registration Successful</h2>
    <p>Name: $name</p>
    <p>Email: $email</p>";
        exit;
    }
}
?>
<?php foreach ($errors as $e)
    echo "<p style='color:red'>$e</p>"; ?>
<form method="POST">
    <input name="name" placeholder="Name" value="<?= $name ?>"><br><br>
    <input name="email" type="email" placeholder="Email" value="<?= $email ?>"><br><br>
    <input name="pass" type="password" placeholder="Password"><br><br>
    <button type="submit">Register</button>
</form>