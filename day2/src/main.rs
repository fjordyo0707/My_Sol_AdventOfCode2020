use std::fs;

#[derive(Debug)]
struct MyStruct {
    min_o : i32,
    max_o : i32,
    target : char,
    request : String,
}

fn my_algorithm(vec_struct : Vec<MyStruct>) -> i32 {
    let mut count_ans : i32 = 0; 
    for my_struct in vec_struct.iter() {
        let first_position = my_struct.request.as_bytes()[my_struct.min_o as usize - 1] as char;
        let second_position = my_struct.request.as_bytes()[my_struct.max_o as usize - 1] as char;
        let mut count_position = 0;
        if first_position == my_struct.target {
            count_position = count_position + 1;
        }
        if second_position == my_struct.target {
            count_position = count_position + 1;
        }
        if count_position == 1 {
            count_ans = count_ans + 1;
        }
    }
    return count_ans;
}

fn main() {
    let filename = "./input/test";
    let contents = fs::read_to_string(filename)
        .expect("Something went wrong reading the file");
    let mut vec : Vec<MyStruct> = Vec::new();

    for line in contents.lines() {
        let mut m_o : i32 = 0;
        let mut ma_o : i32 = 0;
        let mut t : char = 'a';
        let mut req : String = String::new();
        for (i, sp) in line.split_whitespace().enumerate() {
            if i == 0 {
                for (j, c) in sp.split("-").enumerate() {
                    if j == 0 {
                        m_o = c.parse::<i32>().unwrap();
                    } 
                    else if j == 1 {
                        ma_o = c.parse::<i32>().unwrap();
                    }
                }
            }
            else if i == 1 {
                for (j, c) in sp.chars().enumerate() {
                    if j == 0 {
                        t = c;
                    }
                }
            }
            else if i == 2 {
                req = String::from(sp);
            }
        }
        let line_struct = MyStruct{min_o : m_o, max_o: ma_o, target : t, request : req};
        vec.push(line_struct);
    }
    let ans = my_algorithm(vec);
    println!("{}", ans);
}
