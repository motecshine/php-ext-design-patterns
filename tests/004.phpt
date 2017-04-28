--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php
    use PHPDesign\Facade\Facade;
    use PHPDesign\Facade\Bios;
    use PHPDesign\Facade\Linux;
    /* Facade Patterns =.= */
    $bios = new Bios();
    $linux = new Linux();
    $facade = new Facade($linux, $bios);
    $facade->turnOn();
    echo $facade->os->getName() . "\n";
    $facade->turnOff();
?>
--EXPECT--
bios execute
waitForkeyPress
bios launch
Linux
powerDown
linux system halting....
