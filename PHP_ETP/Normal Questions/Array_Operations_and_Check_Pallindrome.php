<!DOCTYPE html>
<html>
<head>
    <title>PHP Array and Palindrome Operations</title>
</head>
<body>
    <h2>Array Operations</h2>
    <?php
    $numbers = array(45, 12, 78, 3, 89, 23, 56);

    echo "Original Array: " . implode(", ", $numbers) . "<br>";

    $min = min($numbers);
    $max = max($numbers);

    echo "Minimum value: $min<br>";
    echo "Maximum value: $max<br>";

    sort($numbers);
    echo "Sorted Array (Ascending): " . implode(", ", $numbers) . "<br>";
    ?>

    <h2>Palindrome Checker</h2>
    <form method="POST">
        Enter a string: <input type="text" name="inputString" required>
        <input type="submit" value="Check">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $input = $_POST['inputString'];

        // Remove non-alphanumeric and convert to lowercase
        $cleaned = strtolower(preg_replace("/[^A-Za-z0-9]/", "", $input));

        // Check palindrome using loop
        $isPalindrome = true;
        for ($i = 0, $j = strlen($cleaned) - 1; $i < $j; $i++, $j--) {
            if ($cleaned[$i] != $cleaned[$j]) {
                $isPalindrome = false;
                break;
            }
        }

        echo "<br><strong>Input:</strong> $input<br>";
        echo $isPalindrome ? "Result: It is a palindrome." : "Result: It is not a palindrome.";
    }
    ?>
</body>
</html>
