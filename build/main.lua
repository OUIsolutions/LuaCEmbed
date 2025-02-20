function main()
    dtw = darwin.dtw
    argv = darwin.argv
    silverchain = darwin.silverchain
    camalgamator = darwin.camalgamator
    candango = darwin.candango
    dtw.remove_any("release")

    if argv.flags_exist({ "silverchain_organize" }) then
        silverchain.generate({
            src = "src",
            project_short_cut = "privateLuaCembed",
            tags = { "dependencies", "consts", "macros", "types", "globals", "fdeclare", "fdef" }
        })
    end

    if argv.flags_exist({ "amalgamate" }) then
        local amalgamation_result = camalgamator.generate_amalgamation(START_POINT)
        dtw.write_file(RELEASE_FOLDER .. "/" .. OUTPUT_SINGLE_FILE, amalgamation_result)
    end

    if argv.flags_exist({ "zip" }) then
        os.execute("zip  release/LuaCEmbed.zip -r src ")
    end


    if argv.flags_exist({ "test" }) then
        local cache = NewCache(CACHE_POINT)
        local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
        Execute_full_test(cache, src_sha)
    end
    if argv.flags_exist({ "create_examples" }) then
        Create_examples()
    end

    if argv.flags_exist({ "create_readme" }) then
        local readme = Create_readme()
    end

    print(ANSI_RESET)
end
