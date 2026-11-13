; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x410096 ((_ extract 1 0) arg0_1)))
(let (($x730217 (= ?x410096 (_ bv3 2))))
(let ((?x472818 (ite $x730217 (_ bv1 32) (_ bv0 32))))
(let (($x521674 (= ?x410096 (_ bv2 2))))
(let ((?x705235 (ite $x521674 (_ bv1 32) (_ bv0 32))))
(let ((?x453866 (bvmul (_ bv4294967295 32) ?x705235)))
(let ((?x692364 (bvadd ?x453866 ?x472818)))
(and (distinct ?x692364 (_ bv0 32)) true)))))))))
(check-sat)
