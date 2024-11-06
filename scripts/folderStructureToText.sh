#!/bin/bash

# Navigate one directory up from the directory where this script is located
cd "$(dirname "$0")/.."

# Define the output file path (in the original directory where the script was located)
output_file="scripts/folder_structure.txt"

# Use the `tree` command to list the directory structure
# If `tree` is not available, we can use `find` to achieve a similar result
if command -v tree &> /dev/null; then
    tree . > "$output_file"
else
    find . -print > "$output_file"
fi

echo "Folder structure has been saved to $output_file"