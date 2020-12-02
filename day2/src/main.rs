use std::fs;

#[derive(Debug)]
struct MyStruct {
    min_o : u32,
    max_o : u32,
    target : String,
    request : String,
}

fn main() {
    let filename = "./input/basic_test";
    let contents = fs::read_to_string(filename)
        .expect("Something went wrong reading the file");

    for line in contents.lines() 
    {
        let mut m_o : u32 = 0;
        let mut ma_o : u32 = 0;
        let mut t : String = String::new();
        let mut req : String = String::new();
        for (i, sp) in line.split_whitespace().enumerate()
        {
            if i == 0 
            {
                for (j, c) in sp.chars().enumerate()
                {
                    if j == 0 
                    {
                        m_o = c.to_digit(10).unwrap();
                    } 
                    else if j == 2
                    {
                        ma_o = c.to_digit(10).unwrap();
                    }
                }
            }
            else if i == 1
            {
                for (j, c) in sp.chars().enumerate()
                {
                    if j == 0 {
                        t = c.to_string();
                    }
                }
            }
            else if i == 2
            {
                req = String::from(sp);
            }
        }
        let line_struct = MyStruct{min_o : m_o, max_o: ma_o, target : t, request : req};
        println!("{:?}", line_struct);
    }
}
