## Minitalk 📬 📮

This project is about creating a program with a client/server. The goal is to communicate client and server using UNIX signals.

Both programs needs to communicate through UNIX signals `SIGSUSR1` and `SIGUSR2`. 
The client encodes each bit of the message using bitwise operations. So the client will take each byte of the message send it bit by bit to the server. It will use `SIGUSR1` to send 1s to the server and `SIGUSR2` to send 0s. 

The server accumulates the received bits and will execute the opposite bitwise operation to build a byte that will be written in the screen until the message sent by the client is complete. 

## Approach 🧠 ⚙️ 
Since the project is about getting familiar with the UNIX signals, I decide to implement the encryption/decryption of the message with bitwise operations because of 2 reasons: 

- There's no need to worry about a strong secure encryption since is not the goal of the project, therefore more secure algorithms like SHA-2 were not consider for this task. 
- There's a need to use the `SIGSUSR1` and `SIGUSR2` signals. So the bitwise operation makes sense for me since I will go for each byte of the message to be send, and for each byte will get each bit conforming the byte. Once I'm working in a bit level, the use of `SIGSUSR1` and `SIGUSR2`makes totally sense since I will be sending 1 and 0 from the client and the server will build the bytes from the bits, and therefore the message.   