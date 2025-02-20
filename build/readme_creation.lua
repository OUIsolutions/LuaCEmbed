function create_c_example(src)
    
    local extension = dtw.newPath(src).get_extension()
    local content = dtw.load_file(src)
    if extension == "c" then
        return "```c\n" .. content .. "\n```"
    end 
    return "```bash\n" .. content .. "\n```"
end

---@return string |nil
function Create_readme()
    HASHTAG = "#"
    local result = candango.Render_text(
        dtw.load_file("extra/INTERNAL.md")
    )
    if result.exist_error then
        print(result.error_message)
        os.exit(1)
    end
    dtw.write_file("README.md", result.render_text)
end
