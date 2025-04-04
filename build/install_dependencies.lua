function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = 'a5502d297da6abff0a85046ecc665415df893628fbc07b95e85c4b7e02acc640'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end

    darwin.dtw.remove_any("dependencies")

    os.execute("mkdir -p dependencies")
    
    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.c -o dependencies/UniversalGarbage.c")
    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.h -o dependencies/UniversalGarbage.h")   

    os.execute("curl -L https://github.com/OUIsolutions/LuaSingleUnity/releases/download/5.4.7/lua_single_unity_custom_onelua.c -o dependencies/lua_single_unity_custom_onelua.c")
    os.execute("curl -L https://github.com/OUIsolutions/LuaSingleUnity/releases/download/5.4.7/lua_single_unity.h -o dependencies/lua_single_unity.h ")


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end
