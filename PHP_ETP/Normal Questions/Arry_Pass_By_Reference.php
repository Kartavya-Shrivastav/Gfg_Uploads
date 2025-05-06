<?php
function doubleValue(&$arr)
{
    foreach ($arr as $i => $val) {
        $arr[$i] = $val * 2;
    }
    echo "<b>Inside Function (Modified Array):</b><br>";
    foreach ($arr as $val)
        echo $val . " ";
}

$original = [5, 10, 15, 20];
echo "<b>Original Array (Before Function Call):</b><br>";
foreach ($original as $val)
    echo $val . " ";

echo "<br><br>";
doubleValue($original);

echo "<br><br><b>Original Array (After Function Call):</b><br>";
foreach ($original as $val)
    echo $val . " ";
?>