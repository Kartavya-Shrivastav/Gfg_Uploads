<?php
class Book {
    private $title, $author, $price;

    function setTitle($t) { if ($t) $this->title = $t; else echo "Invalid title<br>"; }
    function setAuthor($a) { if ($a) $this->author = $a; else echo "Invalid author<br>"; }
    function setPrice($p) { if ($p >= 0) $this->price = $p; else echo "Invalid price<br>"; }

    function getTitle() { return $this->title; }
    function getAuthor() { return $this->author; }
    function getPrice() { return $this->price; }
}

$b1 = new Book();
$b1->setTitle("1984");
$b1->setAuthor("George Orwell");
$b1->setPrice(299);

$b2 = new Book();
$b2->setTitle("Clean Code");
$b2->setAuthor("Robert C. Martin");
$b2->setPrice(-100); // Invalid price

$books = [$b1, $b2];

foreach ($books as $b) {
    echo "<p>Title: ".$b->getTitle()."<br>Author: ".$b->getAuthor()."<br>Price: ".$b->getPrice()."</p><hr>";
}
?>
