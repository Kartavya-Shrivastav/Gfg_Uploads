<?php
// 1. Connect to MySQL
$conn = new mysqli("localhost", "root", "", "");

// 2. Create database
$conn->query("CREATE DATABASE IF NOT EXISTS CookingClasses");
$conn->select_db("CookingClasses");

// 3. Create Instructors table
$conn->query("CREATE TABLE IF NOT EXISTS Instructors (
    instructor_id INT PRIMARY KEY AUTO_INCREMENT,
    instructor_name VARCHAR(100),
    experience_years INT
)");

// 4. Create Classes table
$conn->query("CREATE TABLE IF NOT EXISTS Classes (
    class_id INT PRIMARY KEY AUTO_INCREMENT,
    class_name VARCHAR(100),
    class_date DATE,
    class_fee DECIMAL(10,2),
    instructor_id INT,
    FOREIGN KEY (instructor_id) REFERENCES Instructors(instructor_id)
)");

// 5. Insert sample data
$conn->query("INSERT INTO Instructors (instructor_name, experience_years) VALUES 
    ('Alice', 5), ('Bob', 10), ('Charlie', 3)
");
$conn->query("INSERT INTO Classes (class_name, class_date, class_fee, instructor_id) VALUES
    ('Italian Cooking', '2024-06-01', 650.00, 1),
    ('Baking Basics', '2024-06-05', 450.00, 2),
    ('Advanced Sushi', '2024-06-10', 700.00, 3)
");

// 6. Display instructors teaching classes with fee > 500
$result = $conn->query("
    SELECT i.instructor_name, c.class_name, c.class_fee
    FROM Instructors i
    JOIN Classes c ON i.instructor_id = c.instructor_id
    WHERE c.class_fee > 500
");

echo "<h3>Instructors teaching classes with fee above ₹500</h3>";
echo "<table border='1' cellpadding='8'>
<tr><th>Instructor</th><th>Class</th><th>Fee (₹)</th></tr>";

while ($row = $result->fetch_assoc()) {
    echo "<tr>
        <td>{$row['instructor_name']}</td>
        <td>{$row['class_name']}</td>
        <td>{$row['class_fee']}</td>
    </tr>";
}
echo "</table>";

$conn->close();
?>
