function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = '070e3e3c69cd7b3012346567c7fd164aa42435c72f29d7e43c97da0ffbf2017e'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end

    darwin.dtw.remove_any("dependencies")

    os.execute("mkdir -p dependencies")
    
    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.c -o dependencies/UniversalGarbage.c")
    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.h -o dependencies/UniversalGarbage.h")   

    os.execute("curl -L https://github.com/OUIsolutions/LuaSingleUnity/releases/download/5.4.7/lua_single_unity_classic_onelua.c -o dependencies/lua_single_unity_classic_onelua.c")
    os.execute("curl -L https://github.com/OUIsolutions/LuaSingleUnity/releases/download/5.4.7/lua_single_unity.h -o dependencies/lua_single_unity.h ")


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end
