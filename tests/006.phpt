--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php
    use PHPDesign\Commander\HelloCommand;
    use PHPDesign\Commander\Invoker;
    use PHPDesign\Commander\Receiver;
    use PHPDesign\Commander\AddMessageDateCommand;
    $invoker = new Invoker();
    $receiver = new Receiver();
    $invoker->setCommand(new HelloCommand($receiver));
    $invoker->run();
    var_dump($receiver->getOutput());

    $messageDateCommand = new AddMessageDateCommand($receiver);
    $messageDateCommand->execute();
    $invoker->run();
    var_dump($receiver->getOutput());

    $messageDateCommand->undo();
    $invoker->run();
    var_dump($receiver->getOutput());
?>
--EXPECT--
array(1) {
  [0]=>
  string(12) "Hello World "
}
array(1) {
  [0]=>
  string(23) "Hello World  1993-04-01"
}
array(1) {
  [0]=>
  string(23) "Hello World  1993-04-01"
}
