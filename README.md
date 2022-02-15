# MiniTalk
A small project which involves an introduction to signal handling.
Data will be sent to the server by using the concept of binary encoding/decoding. Using 2 signals, the binary arrays can be transmitted from one program to another, which in order decodes the bits and outputs the string received.

I chose to create a small data acknowledgement system to guarentee that data is received in the correct order, without being forced to sleep on every bit send on the client side (That makes the program faster as well!). The client receives a message for every bit that has been processed by the server.

For ascii printable characters 7 bit system would be sufficient and more efficient than transferring 8 bits. For unicode, 8 bits per character would be neccessary.

1. Make (2 executables created: server and client)
2. Execute server without parameters
3. Read the server PID manually from the terminal
4. Execute the client, first argument being the PID from server
5. The server should now display any argument passed to client!

Possible updates/issues:
1. Bitshifting for bit extraction
