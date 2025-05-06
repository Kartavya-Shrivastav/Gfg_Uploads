<?php

// Connect to MySQL
$conn = new mysqli("localhost", "root", "");
if ($conn->connect_error)
    die("Connection failed: " . $conn->connect_error);

// Create database if not exists
$conn->query("CREATE DATABASE IF NOT EXISTS companyDB");
$conn->select_db("companyDB");

// Create table if not exists
$conn->query("CREATE TABLE IF NOT EXISTS employees (
    employee_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    department VARCHAR(50) NOT NULL,
    salary FLOAT NOT NULL,
    hire_date DATE NOT NULL,
    status ENUM('active','inactive') NOT NULL
)");

// Insert employee
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $conn->real_escape_string($_POST["name"]);
    $dept = $conn->real_escape_string($_POST["department"]);
    $salary = floatval($_POST["salary"]);
    $date = $_POST["hire_date"];
    $status = $_POST["status"];

    if ($name && $dept && $salary && $date && $status) {
        $conn->query("INSERT INTO employees (name, department, salary, hire_date, status)
                                VALUES ('$name', '$dept', $salary, '$date', '$status')");
    }
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>Employee Management</title>
</head>

<body>
    <h2>Add Employee</h2>
    <form method="post">
        Name: <input type="text" name="name" required><br><br>
        Department: <input type="text" name="department" required><br><br>
        Salary: <input type="number" name="salary" step="0.01" required><br><br>
        Hire Date: <input type="date" name="hire_date" required><br><br>
        Status:
        <select name="status" required>
            <option value="active">Active</option>
            <option value="inactive">Inactive</option>
        </select><br><br>
        <button type="submit">Add Employee</button>
    </form>

    <h2>Employee List</h2>
    <table border="1" cellpadding="5">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Department</th>
            <th>Salary</th>
            <th>Hire Date</th>
            <th>Status</th>
        </tr>
        <?php
        $result = $conn->query("SELECT * FROM employees");
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                <td>{$row['employee_id']}</td>
                <td>{$row['name']}</td>
                <td>{$row['department']}</td>
                <td>{$row['salary']}</td>
                <td>{$row['hire_date']}</td>
                <td>{$row['status']}</td>
            </tr>";
        }
        ?>
    </table>
</body>

</html>