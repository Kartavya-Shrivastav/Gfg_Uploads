<?php
$employees = [
    ["name" => "Alice", "salary" => 50000, "tax" => 10],
    ["name" => "Bob", "salary" => 70000, "tax" => 15],
    ["name" => "Charlie", "salary" => 60000, "tax" => 12]
];

function calculateTotalTax($arr) {
    $total = 0;
    foreach ($arr as $e) {
        $tax = $e['salary'] * ($e['tax'] / 100);
        echo "{$e['name']} pays tax: ₹$tax<br>";
        $total += $tax;
    }
    return $total;
}

echo "<b>Total Tax Paid by All Employees:</b> ₹" . calculateTotalTax($employees);
?>
