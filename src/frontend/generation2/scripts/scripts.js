function SearchResultContainer() {
    this.searchResults = new Array();
    this.addResult = function(searchResult) {
        this.searchResults.push(searchResult);
    }
    this.htmlify = function() {
        var htmlString = "";
        for (var i = 0; i < this.searchResults.length; i++) {
            var result = this.searchResults[i];
            htmlString += "<div class='box col1'><b>Search # " + (i + 1) + "</b><br />";
            htmlString += result.htmlify();
            htmlString += "</div>";
        }
        return htmlString;
    }
    this.flush = function() {
        this.searchResults = new Array();
    }
} 

function SearchResult() {
    this.playerName = name;
    this.numbers = new Array();
    this.playerNameAtNumbers = new Array();
    this.addPlayerNameAtNumber = function(playerName, number) {
        this.playerNameAtNumbers.push(new Array(number, playerName));
    }
    this.processNumbers = function(numbers) {
        this.numbers = numbers.split("\s+");
    }
    this.htmlifyNumbers = function() {
        var htmlString = "";
        for (var i = 0; i < this.numbers.length; i++) {
            htmlString += this.numbers[i];
            if (i < this.numbers.length - 1) {
                htmlString += " ";
            }
        }
        return htmlString;
    }
    this.htmlify = function() {
        var htmlString = "";
        htmlString += this.playerName + ": " + this.htmlifyNumbers() + "<br />";
        for (var j = 0; j < this.playerNameAtNumbers.length; j++) {
            var playerNameAtNumber = this.playerNameAtNumbers[j];
            htmlString += playerNameAtNumber[0] + " - " + playerNameAtNumber[1];
            if (j < this.playerNameAtNumbers.length - 1) {
                htmlString += "<br />";
            }
        }
        return htmlString;
    }
} 

var searchResultContainer = new SearchResultContainer();

function loadSearchContent() {
    
    $('#eastContents').empty();
    
    $('#searchInputContents').load('search.html', function() {
        
        $("#searchBoardForm").submit(function(event) {
            
            var $form = $(this);
            
            var playerName = $form.find('input[name="playerName"]').val();
            var playerNumbers = $form.find('input[name="playerNumbers"]').val();
            
            var searchResult = new SearchResult();
            searchResult.playerName = playerName;
            searchResult.processNumbers(playerNumbers);
            searchResult.addPlayerNameAtNumber("Sarie", 4);
            searchResult.addPlayerNameAtNumber("Sarie", 11);
            searchResult.addPlayerNameAtNumber("Piet", 14);
            searchResultContainer.addResult(searchResult);
            
            $("#searchResultContents").html(searchResult.htmlify());
            
            $('#searchHistoryContainer').html(searchResultContainer.htmlify());
            $('#searchHistoryContainer').css("height", "100%");
            
            $('#searchHistoryContainer').masonry({
                itemSelector: '.box',
                columnWidth: 100
            });
            
            return false;
            
        });
        
    });
    
}

function generateBoard() {
    
    $('#centerContents').empty();
    
    $('#centerContents').load('generate-board.html', function() {
        
        if (boardInputHistory != "") {
            $("#generateBoardForm").find('textarea[name="boardinput"]').val(boardInputHistory);
        }
        
        $("#generateBoardForm").submit(function(event) {
            
            //Flush the search history.
            searchResultContainer.flush();
            
            var $form = $(this);
            
            boardInputHistory = $form.find('textarea[name="boardinput"]').val();
            
            /* stop form from submitting normally */
            event.preventDefault();
            
            /* get some values from elements on the page: */
            boarddate = $form.find('input[name="boarddate"]').val(),
            boardname = $form.find('input[name="boardname"]').val(),
            //replacing of LineFeed happening in jQuery now instead of the backend (backend still
            //caters for it though)
            boardinput = $form.find('textarea[name="boardinput"]').val().replace(/\r\n|\r|\n/g, '&'),
            url = '/cgi-bin/WeaponRandomBoard';//$form.attr('action');
                
            /* Send the data using post and put the results in a div */
            $.post(url, {boarddate:boarddate, boardname:boardname, boardinput:boardinput},
                    
                function(data) {
                
                   loadSearchContent();
                
                   $('#centerContents').load('board-tabs.html', function() {
                      
                       $("#tabs").tabs();
                       $("#tabs").layout({
                           defaults: {
                               applyDefaultStyles:true
                           }
                       });
                       $("#tabs > div > div#tabs-1").html(data);
                       $('#board').dataTable({
                           "iDisplayLength": 50,
                           "aaSorting": []
                       });
                       
                   });
                
                }
                  
            );
            
        });
        
        $("#datepicker").datepicker({
            dateFormat: 'yy-mm-dd'
        });
        
    });
    
}

var boardInputHistory = "";

$(document).ready(function () {
    
    $('body').layout({
        
        defaults: {
            applyDefaultStyles:true
        },

        north: {
            showOverflowOnHover:true,
            resizable:false,
            minSize:43,
            maxSize:43
        },
        
        east: {
            size:Math.floor(screen.availWidth / 2),
            minSize:Math.floor(screen.availWidth / 2)
        }
        
    });
    
    $('ul.sf-menu').superfish({
        delay:1000,
        autoArrows:true,
        speed:'fast'
    });
    
    $('#aboutLink').click(function() {
        $('#aboutDialog').dialog({
            modal:true
        });
    });
    
    $('#generateBoardA').click(generateBoard);
    $('#generateBoardB').click(generateBoard);
    
    $('ul.sf-menu').bind('click',function() {
        $(this).hideSuperfishUl();
    });
    
});
