local _M = {}

local function _StrIsEmpty(s)
  return s == nil or s == ''
end

function _M.GetMovies()
  local MovieInfoServiceClient = require "movies_MovieInfoService"
  local GenericObjectPool = require "GenericObjectPool"
  local ngx = ngx
  -- Read the parameters sent by the end user client
  
  ngx.req.read_body()
        local post = ngx.req.get_post_args()

        if (_StrIsEmpty(post.title) ) then
           ngx.status = ngx.HTTP_BAD_REQUEST
           ngx.say("Incomplete arguments")
           ngx.log(ngx.ERR, "Incomplete arguments")
           ngx.exit(ngx.HTTP_BAD_REQUEST)
        end

  ngx.say("Inside Nginx Lua script: Processing Get movie names... Request from: ", post.title)
  
  local client = GenericObjectPool:connection(MovieInfoServiceClient, "movie-info-service", 9093)
  local status, ret = pcall(client.GetMovieNames, client, post.title)
  GenericObjectPool:returnConnection(client)
  ngx.say("Status: ", status)

  if not status then
    
          ngx.status = ngx.HTTP_INTERNAL_SERVER_ERROR
        if (ret.message) then
            ngx.header.content_type = "text/plain"
            ngx.say("Failed to get movie names: " .. ret.message)
            ngx.log(ngx.ERR, "Failed to get movie names: " .. ret.message)
        else
            ngx.header.content_type = "text/plain"
            ngx.say("Failed to get movie names: " )
            ngx.log(ngx.ERR, "Failed to get movie names: " )
        end
        ngx.exit(ngx.HTTP_OK)
    else
        ngx.header.content_type = "text/plain"
    ngx.say("Movie names are: ", ret)
        ngx.exit(ngx.HTTP_OK)
    end

end

return _M
