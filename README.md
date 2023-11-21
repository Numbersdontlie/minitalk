## Minitalk

This project is about creating a program with a client/server. Both programs can only communicate through UNIX signals `SIGSUSR1` and `SIGUSR2`. 
The client encodes each bit of the message and uses `SIGUSR1` to send 1s to the server and `SIGUSR2` to send 0s. The server accumulates the received bits and display the byte once is complete. 