--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php 
use PHPDesign\MacFactory;
use PHPDesign\WinFactory;
$macObj = new MacFactory();
$macObj->CreateButton();
$winObj = new WinFactory();
$winObj->CreateButton();
?>
--EXPECT--
MacFactory: CreateButton
WINFactory: CreateButton
