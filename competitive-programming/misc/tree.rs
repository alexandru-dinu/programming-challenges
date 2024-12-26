use std::collections::HashMap;

#[derive(Copy, Clone)]
struct Tree {
    value: i32,
    children: Vec<Tree>,
}

fn show_tree(tree: Tree, out: &mut String, depth: usize) -> () {
    out.push_str(&" ".repeat(4 * depth));
    out.push_str(format!("{}\n", tree.value).as_str());
    for child in tree.children {
        show_tree(child, out, depth + 1);
    }
}

fn node_count(tree: Tree) -> usize {
    let mut count = 1;
    for child in tree.children {
        count += node_count(child);
    }
    count
}

type Array2D<T> = Vec<Vec<T>>;


fn get_parents(tree: Tree) -> HashMap<i32, i32> {
    let mut parents = HashMap::new();
    let mut stack = vec![tree];
    while let Some(node) = stack.pop() {
        for child in node.children {
            parents.insert(child.value, node.value);
            stack.push(child);
        }
    }
    parents
}

fn build_kth(tree: Tree) -> Array2D<i32> {
    let n = node_count(tree);
    let n_log = (n as f64).log2().floor() as usize;

    let mut up = Array2D::with_capacity(n);
    for _ in 0..n {
        up.push(vec![0; n_log]);
    }

    let parents = get_parents(tree);

    for v in 0..n {
        up[v][0] = parents[&(v as i32)];
        for j in 1..n_log {
            up[v][j] = up[up[v][j - 1] as usize][j - 1];
        }
    }

    up
}

fn main() {
    let tree = Tree {
        value: 0,
        children: vec![
            Tree {
                value: 1,
                children: vec![
                    Tree {
                        value: 3,
                        children: vec![],
                    },
                    Tree {
                        value: 4,
                        children: vec![],
                    },
                ],
            },
            Tree {
                value: 2,
                children: vec![],
            },
        ],
    };

    // let out = build_kth(tree);
    // println!("{}", out[0][0]);

    let out = get_parents(tree);
    println!("{:?}", out);
}