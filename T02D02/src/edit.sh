#!/bin/bash

read -p "Napishite path: " file_path

read -p "Napishite spring chtobi izmenit: " old_string
read -p "Napishite noviy spring: " new_string

sed -i "s/$old_string/$new_string/g" "$file_path"

absolute_file_path=$(realpath "$file_path")
relative_file_path=$(realpath --relative-to="$(git rev-parse --show-toplevel)" "$file_path")
file_hash=$(sha256sum "$file_path" | cut -d ' ' -f 1)
current_date=$(date +"%Y-%m-%d %T")

echo -e "$relative_file_path - $current_date - < s/$old_string/$new_string/g> - sha256" >> "$(git rev-parse --show-toplevel)/src/files.log"

echo "TAYYOR."