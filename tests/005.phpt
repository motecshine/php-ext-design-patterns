--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php
    use PHPDesign\DI\DatabaseConfiguration;
    use PHPDesign\DI\DatabaseConnection;
    $configuration = new DatabaseConfiguration("127.9.0.1", "3306", "root", "1234");
    $connection = new DatabaseConnection($configuration);
    $connection->getDsn();
?>
--EXPECT--
root:1234@:127.9.0.1:3306
