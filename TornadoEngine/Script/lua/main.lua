-- where is json file markup
local jsonPath = "..\\json\\markup.json";
-- destination 
-- local dstPath  = "..\\TestCode\\";
local dstPath  = "..\\..\\..\\TornadoEngine\\Source\\MMOFramework\\TornadoEngine\\Test\\serializator\\";
-- 
local generator = require('generatorSerializable');
generator.generate( jsonPath, dstPath );
