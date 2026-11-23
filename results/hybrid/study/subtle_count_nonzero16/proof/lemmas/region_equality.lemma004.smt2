; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let (($x382033 (= arg0_7 (_ bv0 32))))
(let ((?x529542 (ite $x382033 (_ bv0 32) (_ bv1 32))))
(let ((?x507169 (ite $x382033 (_ bv1 32) (_ bv0 32))))
(let ((?x381844 (bvmul (_ bv4294967295 32) ?x507169)))
(let ((?x474693 (bvadd ?x381844 ?x529542)))
(and (distinct ?x474693 (_ bv0 32)) true)))))))
(check-sat)
