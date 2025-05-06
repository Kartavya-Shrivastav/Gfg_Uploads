<?php
class Car {
    public $make, $model, $year;

    function __construct($make, $model, $year) {
        $this->make = $make;
        $this->model = $model;
        $this->year = $year;
    }

    function displayCarDetails() {
        echo "Car: {$this->make} {$this->model}, Year: {$this->year}<br>";
    }

    function isVintage() {
        return (date("Y") - $this->year) > 20;
    }
}

// Create two Car objects
$car1 = new Car("Toyota", "Corolla", 2000);
$car2 = new Car("Tesla", "Model 3", 2022);

// Display car details
$car1->displayCarDetails();
echo $car1->isVintage() ? "This car is vintage.<br><br>" : "This car is not vintage.<br><br>";

$car2->displayCarDetails();
echo $car2->isVintage() ? "This car is vintage.<br>" : "This car is not vintage.<br>";
?>
