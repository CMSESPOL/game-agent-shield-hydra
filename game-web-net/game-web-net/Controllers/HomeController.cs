using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace game_web_net.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Game1Ceme()
        {
            //ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Game2Ceme()
        {
            //ViewBag.Message = "Your contact page.";

            return View();
        }

        public ActionResult Game3Ceme()
        {
            return View();
        }
    }
}