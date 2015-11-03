---------------------------------------------------------------------
function WriteMethodByNode(node)
  size_stack_methods = size_stack_methods + 1;
  -- формирование методов
  local name_node = node["name"];
  local type_node = node["type"];
  local cnt_child = #node;
  ---------------------------------
  local str_index_param = "";
  local parent = node["parent"];
  for i=1,size_stack_methods do
    if parent==nil then 
      break;
    end;
    local name_parent = parent["name"];
    if #str_index_param==0 then
      str_index_param = "int index"..name_parent;
    else
      str_index_param = "int index"..name_parent..", "..str_index_param;
    end;
    parent = parent["parent"];
  end;
  ---------------------------------
  if cnt_child==0 then -- Const
    fileH:write("  "..type_node.." Get"..name_node.."("..str_index_param..");\n");
    if #str_index_param~=0 then
      str_index_param = str_index_param..", ";
    end;
    fileH:write("  void Set"..name_node.."("..str_index_param..type_node.." v);\n");
    fileH:write("\n");
  else -- Arr
    fileH:write("  int  GetCount"..name_node.."("..str_index_param..");\n");
    if #str_index_param~=0 then
      str_index_param = str_index_param..", ";
    end;
    fileH:write("  void SetCount"..name_node.."("..str_index_param.."int v);\n");
    fileH:write("\n");
  end;
  ---------------------------------
  for index, value in pairs(node) do
    if type(value)=="table" and index~="parent" then
      WriteMethodByNode(value);
    end;
  end;
  size_stack_methods = size_stack_methods - 1;
end;
---------------------------------------------------------------------
function FillHeader()
  fileH:write("#ifndef "..name_packet.."H\n");
  fileH:write("#define "..name_packet.."H\n");
  fileH:write("\n");
  fileH:write("#include \"BasePacket.h\"\n");
  
  for index_add_include, str_include in pairs(add_include_in_header) do
    fileH:write("#include \""..str_include.."\"\n");
  end;

  fileH:write("\n");
  fileH:write("class T"..name_packet.." : public TBasePacket\n");
  fileH:write("{\n");
  fileH:write("public:\n");
  fileH:write("  T"..name_packet.."();\n");
  fileH:write("  virtual ~T"..name_packet.."();\n");
  fileH:write("  void SetDefValue();\n");
  fileH:write("  virtual int         GetID();\n");
  fileH:write("  virtual std::string GetName();\n");
  fileH:write("\n");
  -- перебор иерархии
  for index_node, node in pairs(arr_stack_desc) do
    WriteMethodByNode(node);
  end;
  
  fileH:write("};\n");
  fileH:write("#endif");
  
  fileH:flush();
  fileH:close();
end;
---------------------------------------------------------------------
