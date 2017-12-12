json = require('dkjson')

local generator = { version = "generator 0.01" };

g_jsonPath = "";
g_dstPath = "";
g_nameMarshallizator = "Marshallizator";
g_Header = "/*
g_Header += Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
";
how_to_use = "example how to use:\n".."type = [ bool, uchar, char, ushort, short, uint, int, float, double, long, string ]\n".."modificator = [ \"type\", \"pointer\" ]\n".."container = map, set, vector, list";

function generator.generate( jsonPath, dstPath )
  g_jsonPath = jsonPath;
  g_dstPath = dstPath;
  local resLoadJson = LoadJSON();
  if resLoadJson == false then
    return;
  end;
  -- составить список классов
  CreateMarshallizator();
  print("Generation of C ++ serializable classes is complete.");
end;

function LoadJSON()
  -- load file
  local file_serializators = io.open(g_jsonPath, "r");
  if file_serializators == nil then
    print(help);
    return false;
  end;
  
  content_file = file_serializators:read("*all");
  file_serializators:close();
  -- make table
  local main_table, pos, err = json.decode(content_file)
  if err then
    print ("Fail parse "..jsonPath..":", err);
    return false;
  end;
  return true;
end;

function CreateMarshallizator()
  local fileMarshallizator = io.open(g_dstPath.."_"..g_nameMarshallizator..".h", "w+");
  if fileMarshallizator == nil then
    print("");
    return;
  end;
  fileMarshallizator:write( g_Header );
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