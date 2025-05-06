<?php
function doubleValue($arr) {
    echo "<b>Inside Function (Doubled):</b><br>";
    foreach ($arr as $val) {
        echo $val * 2 . " ";
    }
}

$original = [5, 10, 15, 20];
echo "<b>Original Array (Before Function Call):</b><br>";
foreach ($original as $val) echo $val . " ";

echo "<br><br>";
doubleValue($original);

echo "<br><br><b>Original Array (After Function Call):</b><br>";
foreach ($original as $val) echo $val . " ";
?>
