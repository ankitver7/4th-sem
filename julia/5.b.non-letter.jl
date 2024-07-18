function getnextword(inn::IOStream)
    ch = ' '
    while !eof(inn) && !isletter(ch)
        ch = read(inn, Char)
    end
    if eof(inn)
        return nothing
    end
    word = string(ch)
    ch = read(inn, Char)
    while isletter(ch)
        word *= ch
        ch = read(inn, Char)
    end
    return word
end

function firstlastword()
    inn = open("input.txt", "r")
    first = ""
    last = ""
    word = getnextword(inn)
    if word === nothing
        println("File is empty or no words found.")
        return
    end
    first = word
    last = word
    word = getnextword(inn)
    while word !== nothing
        println(word)
        if word < first
            first = word
        end
        if word > last
            last = word
        end
        word = getnextword(inn)
    end
    close(inn)
    println("\nFirst word is $first")
    println("Last word is $last")
end

firstlastword()
