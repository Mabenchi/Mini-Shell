<br/>
<p align="center">
  <h3 align="center">Mini Shell</h3>

  <p align="center">
    <strong>"Bash shell executable on Unix-like systems using C." </strong>
    <br/>
    <br/>
  </p>
</p>

## Table Of Contents

* [About the Project](#about-the-project)
* [Getting Started](#getting-started)
* [Usage](#usage)

## About The Project
This project is about building a shell interpreter program. By displaying a prompt to enter shell commands, handling parsing and execution.
It also handles:
  - Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
  - Implement redirections ```<``` input, ```>``` output, ```<<```  an input prompt to command, ```>>``` redirect output in append mode.
  - Handle environment variables ($ followed by a sequence of characters) which should expand to their values
  - Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).
  - ...
