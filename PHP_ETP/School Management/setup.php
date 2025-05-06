<?php
// Connect to MySQL server (no specific DB yet)
$conn = new mysqli("localhost", "root", "");

// Step 1: Create the database
$conn->query("CREATE DATABASE IF NOT EXISTS school_management") or die("DB Error");

// Step 2: Select the DB
$conn->select_db("school_management");

// Step 3: Create the students table
$conn->query("CREATE TABLE IF NOT EXISTS students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    age INT,
    grade VARCHAR(5)
)") or die("Table Error");

// Step 4: Insert some sample data
$conn->query("INSERT INTO students (first_name, last_name, age, grade) VALUES
    ('John', 'Doe', 15, 'A'),
    ('Jane', 'Smith', 14, 'B'),
    ('Alice', 'Johnson', 16, 'A'),
    ('Bob', 'Brown', 15, 'C')
") or die("Insert Error");

echo "Database, table, and sample data created successfully!";
$conn->close();
?>
