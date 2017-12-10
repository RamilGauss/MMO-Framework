json = require('dkjson')

local generator = { version = "generator 0.01" };

g_jsonPath = "";
g_dstPath = "";
how_to_use = "example how to use:\n".."type = [ bool, uchar, char, ushort, short, uint, int, float, double, long, string ]\n".."modificator = [ \"type\", \"pointer\" ]\n".."container = map, set, vector, list";

function generator.generate( jsonPath, dstPath )
  g_jsonPath = jsonPath;
  g_dstPath = dstPath;
  loadJSON();
  print("Generation of C ++ serializable classes is complete.");
end;

function loadJSON()
  -- load file
  local file_serializators = io.open(g_jsonPath, "r");
  if file_serializators == nil then
    print(help);
    return;
  end;
  
  content_file = file_serializators:read("*all");
  file_serializators:close();
  -- make table
  local main_table, pos, err = json.decode(content_file)
  if err then
    print ("Fail parse "..jsonPath..":", err);
    return;
  end;
end;

return generator;
--[[ 
print ("useLZ4 ", main_table.useLZ4)

local classes = main_table.class;
for nameClass,descClass in pairs(classes) do
  print("class name="..nameClass);
  for nameMember,descMember in pairs(descClass.member) do
    print("member name="..nameMember);
    if #descMember.type == 0 then
      print("error");
      return;
    end;
    local typeMember = descMember.type[1];
    local modificatorMember = descMember.type[2];
    a = 0;
  end;
end; 
]]