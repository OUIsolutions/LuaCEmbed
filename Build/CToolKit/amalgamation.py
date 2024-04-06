from os.path import join

def get_action(referencer_dir: str, line: str) -> str or None:
    line = line.strip()
    if not line.startswith('#include'):
        return None

    if '"' in line:
        relative_file = line.split('"')[1]
        return join(referencer_dir, relative_file)



def generate_amalgamated_code(starter: str,included=[]) -> str:
    """generate an full amalgamated code of the code you pass
    Args:
        starter (str): the started path of your code ex:'test.h'
        output (str): the output you want to save, if its None it will not save nothing
    Raises:
        FileNotFoundError: if some file were not found

    Returns:
        str: The full amalgamated code
    """
    current_text = ''
    with open(starter) as f:
        # get current dir name
        current_dir = '/'.join(starter.split('/')[:-1])
    
        lines = f.readlines()
        for line in lines:
            ##trim line
            file_to_include = get_action(current_dir, line)

            if file_to_include == None:
                current_text += line
                continue
            
            if file_to_include in included:
                continue

            included.append(file_to_include)
            current_text += generate_amalgamated_code(file_to_include,included)


    return '\n' + current_text +'\n'
