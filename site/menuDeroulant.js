
//Fonction permettant de faire dérouler les liens
function deroulantLien(link) {

    //On définit les variables de styles des IDs et class
    let ulClass = document.getElementsByClassName("ul-modif");
    let types = document.getElementById('types').style;
    let localisation = document.getElementById('localisation').style ;
    let mer = document.getElementById('mer').style;
    let montagne = document.getElementById('montagne').style;
    let international = document.getElementById('international').style ;
    let presentation = document.getElementById('presentation').style;
    let contact = document.getElementById('contact').style;
    let avis = document.getElementById('avis').style;

    if(window.innerWidth >= 1050){
        if (link.className == 'noOpen') {
            if (link.id == 'hebergement') {
                types.visibility = 'visible';
                localisation.visibility = 'visible';
                types.opacity = '1';
                localisation.opacity = '1';
                types.marginTop = '33px';
                localisation.marginTop = '33px';
                link.className = 'open';
            }else if (link.id == 'sejours') {
                mer.opacity = '1';
                montagne.opacity = '1';
                international.opacity = '1';
                mer.visibility = 'visible';
                montagne.visibility = 'visible';
                international.visibility = 'visible';
                mer.marginTop = '33px';
                montagne.marginTop = '33px';
                international.marginTop = '33px';
                link.className = 'open';
            }else if (link.id == 'association') {
                presentation.opacity = '1';
                contact.opacity = '1';
                avis.opacity = '1';
                presentation.visibility = 'visible';
                contact.visibility = 'visible';
                avis.visibility = 'visible';
                presentation.marginTop = '33px';
                contact.marginTop = '33px';
                avis.marginTop = '33px';
                link.className = 'open';
            }
            ulClass[0].setAttribute("style","height : max-content");
            ulClass[1].setAttribute("style","height : max-content");
            ulClass[2].setAttribute("style","height : max-content");
        } else {
            if (link.id == 'hebergement') {
                types.opacity = '0';
                localisation.opacity = '0';
                types.visibility = 'hidden';
                localisation.visibility = 'hidden';
                types.marginTop = '0px';
                localisation.marginTop = '0px';
                link.className = 'noOpen'
            }else if (link.id == 'sejours') {
                mer.opacity = '0';
                montagne.opacity = '0';
                international.opacity = '0';
                mer.visibility = 'hidden';
                montagne.visibility = 'hidden';
                international.visibility = 'hidden';
                mer.marginTop = '0px';
                montagne.marginTop = '0px';
                international.marginTop = '0px';
                link.className = 'noOpen';
            }else if (link.id == 'association') {
                presentation.opacity = '0';
                contact.opacity = '0';
                avis.opacity = '0';
                presentation.visibility = 'hidden';
                contact.visibility = 'hidden';
                avis.visibility = 'hidden';
                presentation.marginTop = '0px';
                contact.marginTop = '0px';
                avis.marginTop = '0px';
                link.className = 'noOpen';
            }
            ulClass[0].setAttribute("style","height : 0px");
            ulClass[1].setAttribute("style","height : 0px");
            ulClass[2].setAttribute("style","height : 0px");
        }
}
    return 0;
}


//Fonction permettant d'activer le menu déroulant
function activeDeroulant() { 
    let menu = document.querySelector('nav');
    menu.style.zIndex = '1';
    menu.style.transform = 'translate(0)';
    menu.style.opacity = '1';
    return 0;
 }

//Fonction permettant de désactiver le menu déroulant
function desactiveDeroulant() { 
    let menu = document.querySelector('nav');
    menu.style = '';
    return 0;
 }

