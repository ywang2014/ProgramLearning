config.toolbar = 'Full';   
  
config.toolbar_Full =   
[      
    ['Image','Flash','Table','HorizontalRule','Smiley','SpecialChar','PageBreak'],   
    ['Styles','Format','Font','FontSize'],  
    ['Maximize', 'ShowBlocks']   
];   
  
config.toolbar_Basic =   
[   
    ['Bold', 'Italic', '-', 'NumberedList', 'BulletedList', '-', 'Link', 'Unlink','-','About']   
];  

CKEDITOR.editorConfig = function( config )   
{   
  
    config.toolbar = 'MyToolbar';//把默认工具栏改为‘MyToolbar’   
  
    config.toolbar_MyToolbar =   
    [     
    ];   
};  
