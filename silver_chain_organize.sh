

#these organize the files following the silverchain rules
## Check https://github.com/OUIsolutions/SilverChain
silverchain -src src \
-tags dependencies consts  macros types globals fdeclare fdef \
--project_short_cut	privateLuaCembed --watch
