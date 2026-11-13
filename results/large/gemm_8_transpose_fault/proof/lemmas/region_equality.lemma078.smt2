; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_26 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_19 () (_ BitVec 32))
(assert
 (let ((?x75257 (bvmul arg0_10 arg1_26)))
(let ((?x7988 (bvmul (_ bv4294967295 32) ?x75257)))
(let ((?x63878 (bvmul arg0_10 arg1_19)))
(let ((?x67770 (bvadd ?x63878 ?x7988)))
(and (distinct ?x67770 (_ bv0 32)) true))))))
(check-sat)
