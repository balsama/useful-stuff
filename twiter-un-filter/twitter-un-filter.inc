<?php
function twitter_un_filter($string) {
  $handles = preg_replace_callback('/@([A-Za-z0-9_]+)/', 
                                    create_function(
                                      '$handles',
                                      '
                                       $username = substr($handles[0], 1);
                                       $handles = "<a href=\"https://twitter.com/" . $username . "\" class=\"twitter-un-filter-link\">" . $handles[0] . "</a>";
                                       return $handles;
                                      '
                                    ),
                                    $string);
  return $handles;
}
?>
