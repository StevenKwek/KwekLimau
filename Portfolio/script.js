// window.onscroll = function() {
//     let header = document.querySelector('.header');
//     if (window.pageYOffset > 0) {
//         header.style.backgroundColor = '#290749';
//     } else {
//         header.style.backgroundColor = 'transparent';
//     }
// };

window.onbeforeunload = () => {
    for(const form of document.getElementsByTagName("form")){
        form.reset();
    }
}


function darkmode(){
    var iconmode = document.getElementById("icon-mode");
    var iconbody = document.getElementById("iconbody");

iconmode.onclick = function(){
    document.body.classList.toggle("dark-theme")
    if(!iconbody.classList.contains("dark-theme")){
        iconmode.src = "/sun.png"
        iconbody.classList.remove("dark-theme")
        iconbody.classList.add("mode")
    }else{
        iconbody.classList.add("dark-theme")
        iconbody.classList.remove("mode")
        iconmode.src = "/moon.png"
    }
}
}

function typinganimate(){
    var i = 0;
    var txt = 'App Development & Web Development';
    var speed = 50;

function typeWriter() {
  if (i < txt.length) {
    document.getElementById("header-animate").innerHTML += txt.charAt(i);
    i++;
    setTimeout(typeWriter, speed);
  }
}
typeWriter()
}

document.addEventListener("DOMContentLoaded", function() {
        const skillsSection = document.querySelector('.skills');
        const progressBars = document.querySelectorAll('.skills-column .skills-content .progress .bar');

        function checkScroll() {
            const sectionPos = skillsSection.getBoundingClientRect().top;
            const screenPos = window.innerHeight;

            if (sectionPos < screenPos) {
                progressBars.forEach(bar => {
                    bar.classList.add('animate');
                });
            }
        }

        window.addEventListener('scroll', checkScroll);
});

document.getElementById('contact-form').addEventListener('submit', function(event) {
    event.preventDefault();

    fetch('https://formspree.io/f/meqbdjeg', {
        method: 'POST',
        body: new FormData(this),
        headers: {
            'Accept': 'application/json'
        }
    }).then(function(response) {
        if (response.ok) {
            document.getElementById('popup-message').style.display = 'flex';
        } else {
            alert('There was an error submitting your form');
        }
    }).catch(function(error) {
        alert('There was an error submitting your form');
    });
});

document.getElementById('close-popup').addEventListener('click', function() {
    document.getElementById('popup-message').style.display = 'none';
});