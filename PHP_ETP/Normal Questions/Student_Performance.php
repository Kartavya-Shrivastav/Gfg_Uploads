<?php
$students = [];

function calculateGrade($avg) {
    if ($avg >= 90) return "A";
    if ($avg >= 75) return "B";
    if ($avg >= 60) return "C";
    if ($avg >= 40) return "D";
    return "F";
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST["name"] ?? "";
    $math = (int)($_POST["math"] ?? 0);
    $science = (int)($_POST["science"] ?? 0);
    $english = (int)($_POST["english"] ?? 0);

    $total = $math + $science + $english;
    $avg = $total / 3;
    $grade = calculateGrade($avg);

    // Store in a multi-dimensional associative array
    $students[] = [
        "name" => $name,
        "scores" => ["Math" => $math, "Science" => $science, "English" => $english],
        "total" => $total,
        "average" => round($avg, 2),
        "grade" => $grade
    ];
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Performance Tracker</title>
    <style>
        body { font-family: Arial; padding: 20px; }
        table, th, td { border: 1px solid black; border-collapse: collapse; padding: 6px; }
    </style>
</head>
<body>

<h2>Enter Student Data</h2>
<form method="POST">
    Name: <input type="text" name="name" required>
    Math: <input type="number" name="math" required>
    Science: <input type="number" name="science" required>
    English: <input type="number" name="english" required>
    <input type="submit" value="Add Student">
</form>

<?php if (!empty($students)): ?>
<h2>Student Performance</h2>
<table>
    <tr>
        <th>Name</th>
        <th>Math</th>
        <th>Science</th>
        <th>English</th>
        <th>Total</th>
        <th>Average</th>
        <th>Grade</th>
    </tr>
    <?php foreach ($students as $s): ?>
        <tr>
            <td><?= htmlspecialchars($s["name"]) ?></td>
            <td><?= $s["scores"]["Math"] ?></td>
            <td><?= $s["scores"]["Science"] ?></td>
            <td><?= $s["scores"]["English"] ?></td>
            <td><?= $s["total"] ?></td>
            <td><?= $s["average"] ?></td>
            <td><?= $s["grade"] ?></td>
        </tr>
    <?php endforeach; ?>
</table>
<?php endif; ?>

</body>
</html>
