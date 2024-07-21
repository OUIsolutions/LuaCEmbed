



local function main()
        local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
        local cache = NewCache(CACHE_POINT)


        local amalgamation_cache = cache.new_element("amalgamation",function ()
            return Generate_amalgamation_recursive(START_POINT)
        end).add_dependencie(src_sha)
        local amalgamation_result = Generate_amalgamation_recursive(START_POINT)

        dtw.write_file(END_TEST_POINT,amalgamation_result)
      if true then
        	return
        end
        Execute_full_test(cache,src_sha)

        Create_examples()
        clib.print(ANSI_RESET)

        local readme = Create_readme()
        if readme ~= nil then
            dtw.write_file("README.md",readme)
        end
        dtw.write_file(OUTPUT_SINGLE_FILE,amalgamation_result)



end

main()