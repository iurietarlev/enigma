# Project Description

This prgogram is a C++ implementation of the functionality of an [Enigma machine](https://en.wikipedia.org/wiki/Enigma_machine). Enigma is the common name for the coding machine used by German forces in the Second World War. Two machines set up in the same way allowed the sending of a message securely between their users.

This program allows for simple input/output operations to configure the Enigma machine from command line arguments and configuration files. The Enigma machine encrypts (or decrypts) messages provided on the standard input stream, outputting the encrypted (or decrypted) message on the standard output stream.

The implementation of the Enigma and its components is done using C++ object oriented concepts.

# How to run

The enigma machine can be configured in with as many rotors as desired and with rotors being in any positions. To pass in the rotors they should be in simple textual file format and passed in on the command line in the following order: `plugboard`, `reflector`, `rotor(1)`, `rotor(2)`, `rotor(n)`, `text to be encrypted`.

An example of how to run it with the already existent files is specified below:

<tt>./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos Hello World</tt>
