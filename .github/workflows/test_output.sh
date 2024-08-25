#!/bin/bash

# Run the compiled program and capture its output
./htop > output.log

# Define expected output
expected_output="[File read successfully]
[File Path: /etc/os-release]
[Successful Read: Yes]
[OS Name: Amazon Linux]
[OS Id: amzn]
[OS Pretty Name: Amazon Linux 2]"

# Compare actual output with expected output
if diff <(echo "$expected_output") output.log; then
    echo "Output is as expected."
    exit 0
else
    echo "Output does not match the expected result."
    exit 1
fi
