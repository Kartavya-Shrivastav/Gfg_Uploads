<?php
$to = "khushisangwan441@gmail.com"; // Use a different email to receive the test
$subject = "Test Email from XAMPP";
$message = "Congratulations! Your XAMPP mail setup is working.";
$headers = "From: kartavyashrivastav28@gmail.com";

if (mail($to, $subject, $message, $headers)) {
    echo "Email sent successfully!";
} else {
    echo "Email sending failed.";
}
?>