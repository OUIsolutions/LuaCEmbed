

---@param waiting_include boolean
---@param inside_string boolean
 function Include_char_to_final(waiting_include,inside_string)

    if waiting_include then
    	return false
    end
    if inside_string then
    	return false
    end
    return true
end
---@param state_machine AMalgamationStateMachine
 function Include_buffer_to_final(state_machine)

    if state_machine.waiting_include then
    	return
    end

    if not state_machine.is_end_string then
    	return
    end

    state_machine.final_text = state_machine.final_text..'"'..state_machine.buffer..'"'
    state_machine.is_end_string = false
    state_machine.buffer = ""

end

---@param content string
---@param index number
---@param inside_string boolean
 function Is_include_point(content,index,inside_string)

    if inside_string then
    	return false
    end

    local INCLUDE_TEXT  = "#include"
    local content_size = clib.get_str_size(content)
    local include_size = clib.get_str_size(INCLUDE_TEXT)
    if index + include_size >= content_size then
    	return false
    end
    local buffer = ""
    for i=index,index + include_size -1 do
    	buffer = buffer..clib.get_char(content,i)
    end

    return buffer == INCLUDE_TEXT
end

---@param state_machine AMalgamationStateMachine
 function Include_char_to_string_buffer(state_machine)

    if not state_machine.inside_string then
        return
    end

    state_machine.buffer = state_machine.buffer..clib.get_char(state_machine.content,state_machine.index)

end

---@param  waiting_include boolean
---@param is_end_string boolean
 function Make_recursive_call(waiting_include,is_end_string)
	if waiting_include and is_end_string then
		return true
	end
end

---@param waiting_include boolean
---@param content string
---@param index number
 function Anulate_inclusion(waiting_include,content,index)
    if waiting_include == false then
    	return false
    end
    if clib.get_char(content,index) == "<" then
    	return true
    end



    return false
end

