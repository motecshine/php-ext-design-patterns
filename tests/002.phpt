--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php 
    
?>
--EXPECT--
