<?php
$conn = new mysqli("localhost", "root", "", "school_management");
if ($conn->connect_error)
    die("Connection failed: " . $conn->connect_error);

$result = $conn->query("SELECT * FROM students");
?>
<!DOCTYPE html>
<html>

<head>
    <title>Students List</title>
</head>

<body>
    <h2>Student Records</h2>
    <table border="1" cellpadding="8">
        <tr>
            <th>ID</th>
            <th>First Name</th>
            <th>Last Name</th>
            <th>Age</th>
            <th>Grade</th>
        </tr>
        <?php while ($row = $result->fetch_assoc()): ?>
            <tr>
                <td><?= $row['id'] ?></td>
                <td><?= htmlspecialchars($row['first_name']) ?></td>
                <td><?= htmlspecialchars($row['last_name']) ?></td>
                <td><?= $row['age'] ?></td>
                <td><?= htmlspecialchars($row['grade']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>
</body>

</html>
<?php $conn->close(); ?>