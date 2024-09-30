#!/bin/bash

read -p "Enter the path: " log_file_path

total_records=$(wc -l < "$log_file_path")
unique_files=$(awk '{print $1}' "$log_file_path" | sort -u | wc -l)
changed_hash=$(grep "Edited" "$log_file_path" | wc -l)

echo "$total_records $unique_files $changed_hash"
