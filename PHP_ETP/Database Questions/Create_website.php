<?php

$conn = new mysqli("localhost", "root", "");
if ($conn->connect_error) {
    die("Initial Connection Failed: " . $conn->connect_error);
}

// Create database if not exists
$conn->query("CREATE DATABASE IF NOT EXISTS mydatabase");

// Now connect to the created DB
$conn->select_db("mydatabase");

// --- Simulated header.php ---
function headerSection($title = "My Website")
{
    echo <<<HTML
<!DOCTYPE html>
<html>
<head>
    <title>$title</title>
    <style>
        body { font-family: Arial; padding: 20px; }
        nav a { margin-right: 15px; color: blue; text-decoration: none; }
        footer { margin-top: 30px; color: gray; font-size: 0.9em; }
    </style>
</head>
<body>
<nav>
    <a href="?page=home">Home</a>
    <a href="?page=about">About</a>
    <a href="?page=contact">Contact</a>
</nav>
<hr>
HTML;
}

// --- Simulated footer.php ---
function footerSection()
{
    echo <<<HTML
<hr>
<footer>&copy; 2025 My Simple PHP Site</footer>
</body>
</html>
HTML;
}

// --- Page Controller Logic ---
$page = $_GET['page'] ?? 'home';
headerSection(ucfirst($page));

switch ($page) {
    case 'about':
        echo "<h2>About Us</h2><p>This is a simple About page.</p>";
        break;

    case 'contact':
        echo "<h2>Contact</h2><p>You can email us at contact@example.com</p>";
        break;

    case 'home':
    default:
        echo "<h2>Welcome to Home Page</h2><p>This is the homepage of our multipage PHP site.</p>";

        // Example DB usage (optional)
        echo "<h3>Test DB Query</h3>";
        $conn->query("CREATE TABLE IF NOT EXISTS visitors (id INT AUTO_INCREMENT PRIMARY KEY, message VARCHAR(255))");
        $conn->query("INSERT INTO visitors (message) VALUES ('Hello from DB')");
        $result = $conn->query("SELECT * FROM visitors ORDER BY id DESC LIMIT 5");
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                echo "<p>ID: {$row['id']} - {$row['message']}</p>";
            }
        } else {
            echo "<p>No data found.</p>";
        }
        break;
}

footerSection();
?>