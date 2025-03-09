# Signal-Based IPC: Client-Server Communication

### Signal-Based Communication in UNIX

Signal-based communication is a lightweight method for inter-process communication (IPC) in UNIX systems. 
It allows processes to send asynchronous notifications using signals like SIGUSR1 and SIGUSR2. Unlike traditional IPC mechanisms (pipes, sockets, or shared memory),
signals are simple and efficient but require careful handling to ensure data integrity. By encoding information into signals, a client can transmit messages bit by bit to a server,
which decodes and processes them in real time. This method is particularly useful for scenarios where minimal system resources are required, making it a robust solution for basic process interactions.

### Features

* The server prints its PID upon launch.
* The client sends a string to the server using its PID.
* The server receives and displays the message immediately.
* Supports multiple clients without restarting the server.
* Ensures efficient transmission speed.
