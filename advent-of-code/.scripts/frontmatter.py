#!/usr/bin/env python3

import argparse
from collections import Counter
from itertools import takewhile
from pathlib import Path

import yaml
from rich.console import Console
from rich.table import Table


def get_frontmatter(f: str) -> dict:
    with open(f, "rt") as fp:
        first = next(fp).strip()
        if first != "---":
            # print(f"No frontmatter found in {f}. Skipping...")
            return dict()
        fm = "".join(takewhile(lambda x: not x.startswith("---"), fp))

    return yaml.safe_load(fm)


def get_tags(fm: dict) -> list[str]:
    if "tags" not in fm:
        # print("No `tags` found in frontmatter. Skipping...")
        return []

    return [x.strip() for x in fm["tags"].split(",")]


def main():
    tag_counter = Counter()
    for f in args.files:
        tags = get_tags(get_frontmatter(f))
        tag_counter.update(tags)

    table = Table(title="Tags", show_header=True, header_style="bold magenta")
    table.add_column("Tag", style="cyan", justify="left")
    table.add_column("Count", style="green", justify="right")

    for tag, count in tag_counter.most_common():
        table.add_row(tag, str(count))

    console = Console()
    console.print(table)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-f", "--files", type=Path, nargs="+", help="Path to md files.")
    args = parser.parse_args()

    main()
